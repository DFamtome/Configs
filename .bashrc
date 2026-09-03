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

# Color support for less
#export LESS_TERMCAP_mb=$'\E[01;31m'       # begin blinking
#export LESS_TERMCAP_md=$'\E[01;38;5;74m'  # begin bold
#export LESS_TERMCAP_me=$'\E[0m'           # end mode
#export LESS_TERMCAP_se=$'\E[0m'           # end standout-mode
#export LESS_TERMCAP_so=$'\E[38;5;246m'    # begin standout-mode - info box
#export LESS_TERMCAP_ue=$'\E[0m'           # end underline
#export LESS_TERMCAP_us=$'\E[04;38;5;146m' # begin underline


# Config perso

alias ls='ls -l --color=auto'
alias l='ls -la --color=auto'
alias grep='grep --color -n'
alias push='git add -A && git commit && git push'

alias reboot='systemctl reboot'
alias poweroff='systemctl poweroff'

tag()
{
	git tag -ma $1 && git push --follow-tag
}

display_git_branch() {
	git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ | [\1]/'
}

_prompt_status() {
  local exit_code=$?
  
  if [ $exit_code -eq 0 ]; then
    # Succès : Check vert
    echo -e "\e[0;32m[✔]"
  elif [ $exit_code -eq 130 ]; then
    # Annulé (Ctrl+C) : Croix bleue
    echo -e "\e[0;34m[✘]"
  else
    # Autre erreur : Croix rouge
    echo -e "\e[0;31m[✘]"
  fi
}

export PS1='$(_prompt_status) \[\e[34m\]le jujudorange \[\e[37m\]:\[\e[32m\] \w\[\e[36m\]$(display_git_branch) '

# Fonction déclenchée AVANT l'exécution de la commande
function timer_start {
  timer=${timer:-$(date +%s%3N)}
}

# Fonction déclenchée APRES l'exécution et AVANT l'affichage du PS1
function timer_stop {
  if [ -n "$timer" ]; then
    local delta=$(($(date +%s%3N) - timer))
    # Convertit les millisecondes en secondes
    local sec=$(bc <<< "scale=3; $delta / 1000")
    # Stocke le résultat formaté pour le PS1
    LAST_EXEC_TIME="${sec}s"
    unset timer
  else
    LAST_EXEC_TIME=""
  fi
}

# Associe les fonctions aux signaux de Bash
trap 'timer_start' DEBUG
PROMPT_COMMAND='timer_stop'

# Intègre le temps dans votre prompt (PS1)
PS1+='\[\e[36m\][${LAST_EXEC_TIME}]\[\e[m\] \n$ '
fastfetch

