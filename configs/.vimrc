" ~/.vimrc

" Basics settings
syntax on

set mouse=a
set number

set sw=4
set ts=4

set autoindent
set smartindent

" Autostart

autocmd VimEnter * wincmd p " Metter le curseur dans la page d'edition

" Vérifiea chaque fois qu'on ferme un buffer/fenêtre
autocmd BufEnter * call QuitIfOnlyUtilitarianLeft()

" Garder l'explorateur a gauche et fixer sa largeur
let g:netrw_banner = 0
let g:netrw_liststyle = 3
let g:netrw_browse_split = 4
let g:netrw_altv = 1
let g:netrw_winsize = 15

function! NetrwMapping()
	" tab = cd
	nmap <buffer> <TAB> gn
endfunction

augroup netrw_mappings
    autocmd!
    autocmd filetype netrw call NetrwMapping()
augroup END

" Raccourcis vim hors-insert 
nnoremap <C-n> :Lex<CR>

nnoremap <C-t> :vertical botright term<CR>
set termwinscroll=10000

nnoremap <C-Left> <C-w>h
nnoremap <C-Down> <C-w>j
nnoremap <C-Up> <C-w>k
nnoremap <C-Right> <C-w>l


" Racourci terminal
tnoremap <Esc> <C-\><C-n> 
tnoremap <C-q> exit<CR>
tnoremap <C-r> cargo run<CR>
tnoremap <C-t> cargo test<CR>
tnoremap <C-m> make<CR>

" Racourcies in-insert

inoremap <C-s> <Esc> :w<CR>i
inoremap <C-up> <Esc> :0<Cr>i

inoremap " ""<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>

" Aparence

set fillchars=vert:\|  
highlight VertSplit ctermbg=15 ctermfg=0 guibg=NONE guifg=#FFFFFF

" Fenêtre active : Texte blanc sur fond noir
highlight StatusLine ctermfg=15 ctermbg=0 guifg=#FFFFFF guibg=#000000 gui=NONE

" Fenêtres inactives : Texte gris sur fond noir (pour bien les distinguer)
highlight StatusLineNC ctermfg=0 ctermbg=15 guifg=#808080 guibg=#000000 gui=NONE

