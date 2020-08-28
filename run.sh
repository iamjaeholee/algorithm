CPP=$1;
make $CPP &&
python3 "$CPP-example.py" | time ./$CPP &&
python3 "$CPP-worst.py" | time ./$CPP &&
rm $CPP
