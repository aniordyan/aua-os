mkdir workshop
cd workshop/
mkdir projects logs notes
ls
cd projects/
vim project1.txt
touch activity.log
vim ideas.txt
mv project1.txt ../
ls
rm activity.log ideas.txt 
ls
touch project1.txt
cd ..
cd logs/
touch activity.log
ls
cd ..
cd notes/
vim ideas.txt
cd ..
cd projects/
ls
mv project1.txt ../
ls
cd ..
ls
cd logs/
mv activity.log workshop.log
cd ..
vim project1.txt 
cd notes/
ls
cp ideas.txt ../ideas_copy.txt
cd ..
ls
mkdir archive
mv ideas_copy.txt ./archive/
ls
cd archive/
ls
cd ..
cd notes/
rm ideas.txt 
cd ..
rmdir projects/
ls
cd archive/
ls
cd ../logs
ls
cd ..
ls
cd ..
vim first_file.txt
ls
mkdir hw1
cd hw1
vim 1.c
vim 2.c
vim 3.c
vim 4.c
vim 5.c
git init
git add .
git commit -m "hw1"
git config --global user.email "ordyanani@gmail.com"
git commit -m "hw1"
git remote add origin git@github.com:aniordyan/aua-os.git
git push -u origin master
git status
git push -u origin master
git remote add origin https://github.com/aniordyan/aua-os.git
ssh-keygen -t ed25519 -C "ordyanani@gmail.com"
cat ~/.ssh/id_ed25519.pub
ssh -T git@github.com
git push -u origin master
ls
cd hw1/
gcc 1.c -o 1
./1
vim 1.c
cd hw1
gcc 2.c -o 2
./2
gcc 3.c -o 3
./3
vim 4.c
vim 5.c
ls
tree workshop/
cat workshop/project1.txt 
exit
