CPP=$1
g++ -std=c++11 -o $CPP "$CPP.cpp" &&
python3 "$CPP-example.py" | time ./$CPP
rm $CPP
