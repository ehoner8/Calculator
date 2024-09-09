./calc < largetrig.txt > o1.txt 2> e1.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_trigoutrange.sh" $?
    rm o1.txt
    rm e1.txt
    exit 1
fi

./calc_x86 < largetrig.txt > o2.txt 2> e2.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_trigoutrange.sh" $?
    rm o2.txt
    rm e2.txt
    exit 1
fi

diff o1.txt o2.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_trigoutrange.sh" $?
    rm o1.txt
    rm o2.txt
    rm e1.txt
    rm e2.txt
    exit 1
fi

exit 0

