/*
 * ErrorManager.h
 *
 *  Created on: 22 de abr de 2016
 *      Author: lucas
 */

#ifndef ERROR_MANAGER_ERRORMANAGER_H_
#define ERROR_MANAGER_ERRORMANAGER_H_

#include <string.h>
#include <map>

#include "Common/Types/CommonTypes.h"

#include "Error/Types/ErrorTypes.h"

namespace ldk {

class ErrorManager {
public:
    /**
     * \brief The singleton method of this class
     * \return The single instance of this class
     */
    static ErrorManager* GetInstance();

    /**
     * \brief Register the error code and associate an message and severity degree to it.
     * \param code The code to attach the error.
     * \param message The message do be attached to error code
     * \param severity The error severity
     * \return Return true if the error is registered correctly. Return false if the error
     * code alredy exist.
     */
    bool RegisterError(ErrorCode_t code, std::string message, ErrorSeverity severity, std::string module_name);

    /**
     * \brief Returns the error message based on error code.
     * \param code The error code.
     * \return The string attached to selected error code.
     */
    std::string GetErrorMessage(ErrorCode_t code);

    /**
     * \brief Returns the error severity based in error code.
     * \param code The error code.
     * \return The severity of selected error code.
     */
    ErrorSeverity GetErrorSeverity(ErrorCode_t code);

    /**
     * \brief Returns the module owner of error code.
     * \param code The error code.
     * \return The owner module.
     */
    std::string GetErrorModule(ErrorCode_t code);

private:
    /**
     * \brief Default class constructor is private because a singleton pattern.
     */
    ErrorManager();

    /**
     * \brief Default class destructor is private because a singleton pattern.
     */
    ~ErrorManager();

    /**
     * \brief Pointer to unique instance of this class
     */
    static ErrorManager* instance_;

    /**
     * A map of errors
     */
    ErrorCodeMap_t error_code_map_;
};

} /* namespace ldk */

#endif /* ERROR_MANAGER_ERRORMANAGER_H_ */
