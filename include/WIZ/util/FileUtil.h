//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef GAMETEMPLATE_FILEUTIL_H
#define GAMETEMPLATE_FILEUTIL_H

#include <sstream>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#endif

namespace wiz {
	/**
	 * Checks if a folder exists
	 *
	 * @param directory path to the folder to check.
	 * @return true if the folder exists, false otherwise.
	 */
	bool directoryExists(const char* directory);

	bool directoryExists(const std::string& directory);

	/**
	 * Recursively create directories for the given path
	 *
	 * @param[in] path the full path of the directory to create.
	 * @return zero on success, otherwise -1.
	 */
	int ensureDirectory(const char* path);

	int ensureDirectory(const std::string& path);
}

#endif //GAMETEMPLATE_FILEUTIL_H
