clang++ -Wall -Wextra -Werror -W -std=c++98 *.cpp -o start
./start | cat -e > tmp.txt
diff tmp.txt output.txt
rm start tmp.txt
