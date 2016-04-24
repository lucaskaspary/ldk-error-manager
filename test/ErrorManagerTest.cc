/*
 * TelnetServer_test.cc
 *
 *  Created on: 22 de abr de 2016
 *      Author: lucas
 */
#include <iostream>

#include "Error/Manager/ErrorManager.h"

#include "gtest/gtest.h"

using ldk::ErrorManager;
using ldk::ErrorCode_t;
using ldk::ErrorSeverity;

#define TEST_ERROR_CODE_A 100
#define TEST_ERROR_MESSAGE_A "test_error_a"
#define TEST_ERROR_SEVERITY_A ErrorSeverity::ERROR
#define TEST_ERROR_MODULE_A "module_a"

#define TEST_ERROR_CODE_B 200
#define TEST_ERROR_MESSAGE_B "test_error_b"
#define TEST_ERROR_SEVERITY_B ErrorSeverity::CRITICAL
#define TEST_ERROR_MODULE_B "module_b"

TEST(ErrorManager, instantiation)
{
    ErrorManager* instance = nullptr;
    EXPECT_NO_THROW(instance = ErrorManager::GetInstance());
    EXPECT_NE(instance, nullptr);
}

TEST(ErrorManager, singleton)
{
    ErrorManager* instance_a = nullptr;
    ErrorManager* instance_b = nullptr;
    EXPECT_EQ(instance_a, instance_b);

    EXPECT_NO_THROW(instance_a = ErrorManager::GetInstance());
    EXPECT_NO_THROW(instance_b = ErrorManager::GetInstance());

    EXPECT_EQ(instance_a, instance_b);
}

/**
 * This error occurs because the error code already be registered
 */
TEST(ErrorManager, register_duplicated_error)
{
    ErrorManager* instance = nullptr;
    EXPECT_NO_THROW(instance = ErrorManager::GetInstance());

    EXPECT_EQ(instance->RegisterError(TEST_ERROR_CODE_A,TEST_ERROR_MESSAGE_A,
            TEST_ERROR_SEVERITY_A, TEST_ERROR_MODULE_A), true);

    EXPECT_EQ(instance->RegisterError(TEST_ERROR_CODE_A,TEST_ERROR_MESSAGE_B,
            TEST_ERROR_SEVERITY_B, TEST_ERROR_MODULE_B), false);
}

TEST(ErrorManager, check_error_message)
{
    ErrorManager* instance = nullptr;
    EXPECT_NO_THROW(instance = ErrorManager::GetInstance());
    std::string error_message;
    EXPECT_NO_THROW(error_message = instance->GetErrorMessage(TEST_ERROR_CODE_A));
    ASSERT_STREQ(error_message.c_str(),TEST_ERROR_MESSAGE_A);
}

TEST(ErrorManager, check_error_severity)
{
    ErrorManager* instance = nullptr;
    EXPECT_NO_THROW(instance = ErrorManager::GetInstance());
    ErrorSeverity severity = ErrorSeverity::UNKNOWN;
    EXPECT_NO_THROW(severity = instance->GetErrorSeverity(TEST_ERROR_CODE_A));
    ASSERT_EQ(severity, TEST_ERROR_SEVERITY_A);
}

TEST(ErrorManager, check_error_module)
{
    ErrorManager* instance = nullptr;
    EXPECT_NO_THROW(instance = ErrorManager::GetInstance());
    std::string module_name = "";
    EXPECT_NO_THROW(module_name = instance->GetErrorModule(TEST_ERROR_CODE_A));
    ASSERT_EQ(module_name, TEST_ERROR_MODULE_A);
}
