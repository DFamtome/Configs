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

# Config perso
alias loop='~/.config/shell/loop.sh'
alias c_builder='~/.config/shell/c_builder.sh'

alias ls='ls -l --color=auto'
alias l='ls -la --color=auto'
alias grep='grep --color'
alias mnt='udisksctl mount -b'
alias umnt='udisksctl unmount -b'

alias reboot='systemctl reboot'
alias poweroff='systemctl poweroff'

# Debian config
alias dmaj='sudo apt update && sudo apt upgrade'
alias fmaj='sudo apt update'
alias amaj='sudo apt upgrade'

function clang()
{
	if [ -f "./*/*.[ch]" ]; then
		clang-format -i ./*/*.[ch]
	fi

	if [ -f "./*.[ch]" ]; then 
		clang-format -i ./*.[ch]
	fi
}

function push()
{
	clang-format -i $(git ls-files | grep -E "\.[ch]$")
	git add -A && git commit && git push
}

tag()
{
	git tag -ma $1 && git push --follow-tag
}

display_git_branch() {
	git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ | [\1]/'
}

_prompt_status() {
  exit_code=$?
  
  if [ $exit_code -eq 0 ]; then
    # Succès : Check vert
    echo -e "\e[0;32m[✔]"
  elif [ $exit_code -eq 130 ]; then
    # Annulé (Ctrl+C) : Croix bleue
    echo -e "\e[0;34m[✘]"
  else
    # Autre erreur : Croix rouge
    echo -e "\e[0;31m[✘ ($exit_code)]"
  fi
}

# Fonction déclenchée AVANT l'exécution
function timer_start {
  [ -z "$timer" ] && timer=${EPOCHREALTIME:-$(date +%s.%N)}
}

# Fonction déclenchée APRES l'exécution et AVANT le PS1
function timer_stop {
  if [ -n "$timer" ]; then
    local now=${EPOCHREALTIME:-$(date +%s.%N)}
    
    # Calcul et formatage à 5 décimales via awk (présent par défaut)
    LAST_EXEC_TIME=$(awk -v start="$timer" -v end="$now" 'BEGIN { printf "%.5fs", end - start }')
    unset timer
  else
    LAST_EXEC_TIME=""
  fi
}

# Association aux hooks Bash
trap 'timer_start' DEBUG
PROMPT_COMMAND='timer_stop'

PS1='$(_prompt_status) \[\e[34m\]le jujudorange \[\e[37m\]:\[\e[32m\] \w \e[33m\][${LAST_EXEC_TIME}]\[\e[m\]\e[36m\]$(display_git_branch) \e[37m\] \n$ '
fastfetch



