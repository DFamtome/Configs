# èstétike
PS1="\e[31m\]The goat :\e[34m\] \w\n\e[37m\]$ "

# Alias
alias tp='cd ~/Documents/tp'

# Push function

push() {
	git add .
	git commit -m $MSG
	git push
};
