echo WARNING this operation will destroy your current configuration!
echo Continue ? \(Enter to confirm or Ctrl+C to cancel\)

read $respond

if [ -z $repond ]
then
	cp i3 ~/.config/ -r
	cp -r picom ~/.config

	cp .bashrc ~/
	cp .vimrc ~/

	echo Is it the nix verssion ?

	read $respond
	if [ -z "$repond" ]
	then
		cp nixpkgs_import ~/.config/i3
	fi
fi
