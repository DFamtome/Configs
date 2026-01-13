echo WARNING ! this operation has going to delete your current configuration !
echo Continue ? [y/n]
read $respond

if [$respond = "y"] then 

	cp -r i3/ ~/.config/
	cp -r picom/ ~/.config

	cp .bashrc ~/.bashrc
	cp .vimrc ~/.vimrc

	echo Load the repo config into this device finish !

else  

	echo Operation canceled
fi
