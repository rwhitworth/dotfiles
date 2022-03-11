# docker for mac specific
# tell 'docker build' to output normal output and not the fancy (useless) Mac/Apple output
export DOCKER_BUILDKIT=0

# Mac OS zsh warnings
export BASH_SILENCE_DEPRECATION_WARNING=1

# homebrew specific
export HOMEBREW_NO_AUTO_UPDATE=1
export HOMEBREW_NO_INSTALL_CLEANUP=1
export HOMEBREW_NO_INSTALLED_DEPENDENTS_CHECK=1
eval "$(/opt/homebrew/bin/brew shellenv)"

# rbenv specific
eval "$(rbenv init -)"

# brew's bash auto completion
[[ -r "/opt/homebrew/etc/profile.d/bash_completion.sh" ]] && . "/opt/homebrew/etc/profile.d/bash_completion.sh"

# git auto completion
if [ -f ~/.git-completion.bash ]; then
  . ~/.git-completion.bash
fi

# npm auto completion
if [ -f ~/.npm-completion.bash ]; then
  . ~/.npm-completion.bash
fi

# export PS1='\W \$ '
export PS1='\W$(current_git_branch) \$ '

test -e "${HOME}/.iterm2_shell_integration.bash" && source "${HOME}/.iterm2_shell_integration.bash"

alias e='date +"%s"'
alias ls='ls -la'
alias sl='ls'
alias vscode="/Applications/Visual\ Studio\ Code.app/Contents/Resources/app/bin/code ."
