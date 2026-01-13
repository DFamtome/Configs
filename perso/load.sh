echo WARNING ! this operation has going to delete your current configuration !
echo Continue ? \(enter to \continue or Ctrl+c to cancel\)
read $respond

if [ -z "$respond" ] 
then 

	cp -r i3/ ~/.config/
	cp -r picom/ ~/.config

	cp .bashrc ~/.bashrc
	cp .vimrc ~/.vimrc

	echo Load the repo config into this device finish !

else  

	echo Operation canceled
fi
