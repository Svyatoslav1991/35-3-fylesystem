TASK 35.3 FILESYSTEM

What should be done
We now have the ability to recursively traverse directories, that is, get a list of all files, directories (and subdirectories) contained in a specified path.
To do this, the standard library has std::filesystem::recursive_directory_iterator, which takes as input a path that it will traverse recursively.
At each step it will produce the next path, this can be either a directory or a regular file.
For example, code
for(auto& p: fs::recursive_directory_iterator("D:\\dir1"))
         std::cout << p.path() << '\n';
will display the full paths to all files and subdirectories in the D:\dir1 directory.
Calling p.path() returns an object of type std::filesystem::path, which allows you to:

Determine whether it is a file or a directory using the is_regular_file() method.
Get the extension for a regular file using the extension() method.
Using the compare() method, you can compare an extension with an arbitrary string: p.path().extension().compare(“.torrent”).

  Create a lambda function that takes as input a file system path and the searched extension as a string, and returns a list of file names that have the given extension().
Our function declaration might start like this:
auto recursiveGetFileNamesByExtension =
        [](std::filesystem::path path,
           const std::string extension)
