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


_timer_start() {
  _cmd_start=$(date +%s%N)
}

_timer_stop() {
  local exit_code=$?

  # 1. Gestion du symbole selon le code de retour
  if [ $exit_code -eq 0 ]; then
    local status_icon="\[\e[1;32m\][✔]\[\e[0m\]"
  elif [ $exit_code -eq 130 ]; then
    local status_icon="\[\e[1;34m\][✘]\[\e[0m\]"
  else
    local status_icon="\[\e[1;31m\][✘]\[\e[0m\]"
  fi

  # 2. Calcul du temps d'exécution
  if [ -n "$_cmd_start" ]; then
    local _cmd_end=$(date +%s%N)
    local diff=$(( (_cmd_end - _cmd_start) / 1000000 ))
    if [ $diff -ge 1000 ]; then
      _elapsed="$(( diff / 1000 )).$(( diff % 1000 ))s"
    else
      _elapsed="${diff}ms"
    fi
    unset _cmd_start
  else
    _elapsed="0ms"
  fi

  # 3. Mise à jour du prompt complet
  PS1="${status_icon} \e[34m\]le jujudorange \e[37m\]:\e[32m\] \w\e[36m\]$(display_git_branch)\e[37m\] \[\e[0;35m\](${_elapsed})\[\e[0m\] \n$ "
}

trap '_timer_start' DEBUG
PROMPT_COMMAND='_timer_stop'
fastfetch
