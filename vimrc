" ~/.vimrc

" Basics settings
syntax on

set mouse=a
set number

set sw=4
set ts=4

" Autostart
autocmd VimEnter * Lex

autocmd VimEnter * wincmd p " Metter le curseur dans la page d'edition

" Ferme les fenettres non utiles s'il ne reste plus que ca
function! QuitIfOnlyUtilitarianLeft()
    " Compte le nombre de fenêtres ouvertes
    let l:win_count = winnr('$')
    if l:win_count > 1
        return
    endif

    " Récupère le type de la dernière fenêtre restante
    let l:buf_type = getbufvar(winbufnr(1), "&buftype")
    let l:file_type = getbufvar(winbufnr(1), "&filetype")

    " Si la dernière fenêtre est un terminal ou Netrw (Lex), on quitte
    if l:buf_type == 'terminal' || l:file_type == 'netrw'
        quit
    endif
endfunction

" Vérifiea chaque fois qu'on ferme un buffer/fenêtre
autocmd BufEnter * call QuitIfOnlyUtilitarianLeft()

" Garder les tab toujours visible en haut
set hidden 

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

nnoremap <C-s> :w<CR>
nnoremap <C-q> :q<CR>
nnoremap <C-Right> :tabn<CR>
nnoremap <C-Left> :tabp<CR>
nnoremap <C-up> :0 <Cr>

nnoremap <C-t> :vertical botright term<CR>
set termwinscroll=10000

nnoremap <C-Left> <C-w>h
nnoremap <C-Down> <C-w>j
nnoremap <C-Up> <C-w>k
nnoremap <C-Right> <C-w>l

nnoremap <S-Left> <C-w><S-h>
nnoremap <S-Down> <C-w><S-j>
nnoremap <S-Up> <C-w><S-k>
nnoremap <S-Right> <C-w><S-l>


" Racourci terminal
tnoremap <Esc> <C-\><C-n> 
tnoremap <C-q> exit<CR>
tnoremap <C-r> cargo run<CR>
tnoremap <C-t> cargo test<CR>
tnoremap <C-n> make<CR>

" Racourcies in-insert

inoremap <C-s> <Esc> :w<CR>i
inoremap <C-up> <Esc> :0<Cr>i

inoremap " ""<left>
inoremap ' ''<left>
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

