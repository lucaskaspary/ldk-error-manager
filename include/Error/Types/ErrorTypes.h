/*
 * ErrorTypes.h
 *
 *  Created on: 22 de abr de 2016
 *      Author: lucas
 */

#ifndef ERROR_TYPES_ERRORTYPES_H_
#define ERROR_TYPES_ERRORTYPES_H_

#include <string>
#include <map>

#include "Common/Types/CommonTypes.h"

namespace ldk {

class ErrorEntry {
public:
    ErrorCode_t code_;
    std::string message_;
    ErrorSeverity severity_;
    std::string module_name_;
};

typedef std::map<ErrorCode_t, ErrorEntry> ErrorCodeMap_t;

} // namespace ldk


#endif /* ERROR_TYPES_ERRORTYPES_H_ */
