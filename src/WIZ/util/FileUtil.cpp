//
// Created by Alexander Winter on 2022-02-10.
//

#include "WIZ/util/FileUtil.h"

int internal_mkdir(const char *path) {
#ifdef _WIN32
    return ::_mkdir(path);
#else
    return ::mkdir(path, 0755);
#endif
}

bool wiz::directoryExists(const char* directory) {
    struct stat st;
    stat(directory, &st);
    return st.st_mode & S_IFDIR;
}

int wiz::ensureDirectory(const char* path) {
    std::string current_level;
    std::string level;
    std::stringstream ss(path);

    // split path using slash as a separator
    while(std::getline(ss, level, '/')) {
        current_level += level; // append folder to the current level

        // create current level
        if (!directoryExists(current_level.c_str()) && internal_mkdir(current_level.c_str()) != 0)
            return -1;

        current_level += "/"; // don't forget to append a slash
    }

    return 0;
}

bool wiz::directoryExists(const std::string& directory) {
    return directoryExists(directory.c_str());
}

int wiz::ensureDirectory(const std::string& path) {
    return ensureDirectory(path.c_str());
}
