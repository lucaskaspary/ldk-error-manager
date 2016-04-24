/*
 * ErrorManager.cc
 *
 *  Created on: 22 de abr de 2016
 *      Author: lucas
 */

#include "Error/Manager/ErrorManager.h"

namespace ldk {

ErrorManager* ErrorManager::instance_ = nullptr;

ErrorManager::ErrorManager() {
    // TODO Auto-generated constructor stub

}

ErrorManager::~ErrorManager() {
    // TODO Auto-generated destructor stub
}

ErrorManager* ErrorManager::GetInstance() {
    if(!instance_){
        instance_ = new ErrorManager();
    }
    return instance_;
}

bool ErrorManager::RegisterError(ErrorCode_t code, std::string message, ErrorSeverity severity, std::string module_name) {
    if ( error_code_map_.find(code) == error_code_map_.end() ) {
        ErrorEntry map_entry;
        map_entry.code_ = code;
        map_entry.message_ = message;
        map_entry.severity_ = severity;
        map_entry.module_name_ = module_name;
        error_code_map_[code] = map_entry;
        return true;
    } else {
      // exist
        return false;
    }
}

std::string ErrorManager::GetErrorMessage(ErrorCode_t code) {
    if ( error_code_map_.find(code) == error_code_map_.end() ) {
        // Not found
        return "Unknown error code";
    } else {
        // found
        return error_code_map_[code].message_;
    }
}

ErrorSeverity ErrorManager::GetErrorSeverity(ErrorCode_t code) {
    if ( error_code_map_.find(code) == error_code_map_.end() ) {
        // Not found
        return ErrorSeverity::UNKNOWN;
    } else {
        // found
        return error_code_map_[code].severity_;
    }
}

std::string ErrorManager::GetErrorModule(ErrorCode_t code) {
    if ( error_code_map_.find(code) == error_code_map_.end() ) {
        // Not found
        return "";
    } else {
        // found
        return error_code_map_[code].module_name_;
    }
}

} /* namespace ldk */
