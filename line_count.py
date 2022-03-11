import os

root_dir = '.'
count = 0
file_count = 0

for subdir, dirs, files in os.walk(root_dir):
        for file in files:
            is_parser = file == "Parser.cpp" or file == "Parser.hpp"
            if is_parser:
                continue

            if file[-3:] == "cpp" or file[-3:] == "hpp": 
                with open(os.path.join(subdir, file), 'r') as f:
                    file_count += 1
                    count += len(f.readlines())

print(count, file_count)