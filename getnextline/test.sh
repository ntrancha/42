#!/bin/sh

echo  "" > result*.txt
echo "1234567890" > file1.txt
echo  "1234567890\n" > file2.txt
echo  "1234567890\n1234567890" > file3.txt
echo  "1234567890\n\n1234567890" > file4.txt
echo  "1234567890\n\n" > file5.txt
echo  "1234567890\n\n\n" > file6.txt
echo  "\n\n\n\n" > file7.txt
echo  "\n" > file8.txt
echo  "1234567890\01234567890" > file9.txt
echo  "1234567890\2001234567890" > file10.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" > file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd\n" >> file11.txt
echo "123412313215484a6z4e6azea5z1e5a3ze51za35d11az3d51az35e15zad13azd" >> file11.txt
cat file1.txt | ./a.out > result1.txt
cat file2.txt | ./a.out > result2.txt
cat file3.txt | ./a.out > result3.txt
cat file4.txt | ./a.out > result4.txt
cat file5.txt | ./a.out > result5.txt
cat file6.txt | ./a.out > result6.txt
cat file7.txt | ./a.out > result7.txt
cat file8.txt | ./a.out > result8.txt
cat file9.txt | ./a.out > result9.txt
cat file10.txt | ./a.out > result10.txt
cat file11.txt | ./a.out > result11.txt
echo "fichier 1"
echo ""
cat file1.txt
echo ""
cat result1.txt
echo ""
diff file1.txt result1.txt
echo ""
echo "fichier 2"
echo ""
cat file2.txt
echo ""
cat result2.txt
echo ""
diff file2.txt result2.txt
echo ""
echo "fichier 3"
echo ""
cat file3.txt
echo ""
cat result3.txt
echo ""
diff file3.txt result3.txt
echo ""
echo "fichier 4"
echo ""
cat file4.txt
echo ""
cat result4.txt
echo ""
diff file4.txt result4.txt
echo ""
echo "fichier 5"
echo ""
cat file5.txt
echo ""
cat result5.txt
echo ""
diff file5.txt result5.txt
echo ""
echo "fichier 6"
echo ""
cat file6.txt
echo ""
cat result6.txt
echo ""
diff file6.txt result6.txt
echo ""
echo "fichier 7"
echo ""
diff file7.txt result7.txt
echo ""
echo "fichier 8"
echo ""
diff file8.txt result8.txt
echo ""
echo "fichier 9"
echo ""
diff file9.txt result9.txt
echo ""
echo "fichier 10"
echo ""
diff file10.txt result10.txt
echo ""
echo "fichier 11"
echo ""
diff file11.txt result11.txt
echo ""
echo "FIN"
echo ""
