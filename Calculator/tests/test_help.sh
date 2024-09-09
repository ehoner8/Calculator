./calc -h > o1.txt 2> e1.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_help.sh" $?
    rm o1.txt
    rm e1.txt
    exit 1
fi


diff o1.txt usage.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_help.sh" $?
    rm o1.txt
    rm e1.txt
    exit 1
fi

exit 0
