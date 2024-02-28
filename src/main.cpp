#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

int main() {
	std::cout << "\tTASK 35.3 FILESYSTEM\n\n";

	auto recursiveGetFileNamesByExtension = [](fs::path path, const std::string extension) {
		std::vector<std::string> vFiles;

		try
		{
			for (const auto& p : fs::recursive_directory_iterator(path))
			{
				if (fs::is_regular_file(p.path()) && p.path().extension() == extension)
				{
					vFiles.push_back(p.path().filename().string());
				}
			}
		}
		catch (const fs::filesystem_error& e)
		{
			std::cerr << "Filesystem error: " << e.what() << '\n';
		}
		

		return vFiles;
	};

	fs::path dir("D:\\dir1");
	std::string extension = ".txt";

	std::vector<std::string> vFiles = recursiveGetFileNamesByExtension(dir, extension);

	std::cout << "Files in directory " << dir.filename() << " with extension " << extension << ":\n";

	for (const auto& file : vFiles)
	{
		std::cout << file << "\n";
	}

	return 0;
}