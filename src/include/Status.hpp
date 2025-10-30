//
// Created by - on 10/30/25.
//

#ifndef TASK_CLI_STATUS_HPP
#define TASK_CLI_STATUS_HPP

#include <string_view>

enum class Status {
    ToDo,
    InProgress,
    Done
};

constexpr std::string_view status_string(Status s) {
    switch (s) {
        case Status::ToDo:          return "todo";
        case Status::InProgress:    return "in-progress";
        case Status::Done:          return "done";
    }
    return "Unknown";
}

#endif //TASK_CLI_STATUS_HPP