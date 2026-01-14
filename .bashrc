# ~/.bashrc

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

if [ -d ~/afs/bin ] ; then
	export PATH=~/afs/bin:$PATH
fi

if [ -d ~/.local/bin ] ; then
	export PATH=~/.local/bin:$PATH
fi

export LANG=fr_FR.utf8
export NNTPSERVER="news.epita.fr"

export EDITOR=vim
#export EDITOR=emacs

# Color support for less
#export LESS_TERMCAP_mb=$'\E[01;31m'       # begin blinking
#export LESS_TERMCAP_md=$'\E[01;38;5;74m'  # begin bold
#export LESS_TERMCAP_me=$'\E[0m'           # end mode
#export LESS_TERMCAP_se=$'\E[0m'           # end standout-mode
#export LESS_TERMCAP_so=$'\E[38;5;246m'    # begin standout-mode - info box
#export LESS_TERMCAP_ue=$'\E[0m'           # end underline
#export LESS_TERMCAP_us=$'\E[04;38;5;146m' # begin underline


# Config perso

alias ls='ls --color=auto'
alias l='ls -la --color=auto'
alias grep='grep --color -n'
alias commit='git add -A && git commit'
alias mount='sudo mount'

alias cl='git clone'
alias rd='rm -rf '
alias tag='git tag -ma'
alias push='git push'

alias reboot='systemctl reboot'
alias poweroff='systemctl poweroff'


PS1='\e[34m\]Le jujudorange \e[37m\]:\e[32m\] \w \e[37m\]\n$ '
