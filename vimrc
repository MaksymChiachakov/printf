" enable mouse support (uncomment this)
set mouse=a

" use tabs not spaces
set noexpandtab

" set the tab display to 4 spaces
set tabstop=4
set shiftwidth=4

" sets line number and relative number
set number
set relativenumber

" autoindent settings
set autoindent
set smartindent

" color the 80th col
set colorcolumn=80

" better colors, doesn't work with all terminals/settings
set termguicolors

" search highlighting
set hlsearch
set incsearch

" Show command in the bottom bar
set showcmd

" Show incomplete commands
set showmode

" Automatically read files when changed outside of Vim
set autoread

" Enable file type detection and indentation
filetype plugin indent on

" sets the leader key to space
" useful for shortcuts
nnoremap <SPACE> <Nop>
let mapleader = " "

" leader (space) then y --> copy the selection in visual mode to the clipboard
vnoremap <leader>y "ay :<C-u>call system('xclip -selection clipboard', @a)<CR>


" TAB MAPPINGS " 
" Open a new tab
nnoremap <leader>tn :tabnew<CR>

" Close the current tab
nnoremap <leader>tc :tabclose<CR>

" Navigate to the next tab
nnoremap <leader>tl :tabnext<CR>

" Navigate to the previous tab
nnoremap <leader>th :tabprevious<CR>

" Move the current tab to the left
nnoremap <leader>tL :-tabmove<CR>

" Move the current tab to the right
nnoremap <leader>tH :+tabmove<CR>

" Go to the first tab
nnoremap <leader>t1 :tabfirst<CR>

" Go to the last tab
nnoremap <leader>t$ :tablast<CR>

" noh to remove search highlights
nnoremap <leader>h :noh<CR>

" Define a function to toggle the display of invisible characters
function! ToggleInvisibleChars()
  if &list
    set nolist
    highlight clear Whitespace
  else
    set list
    set listchars=tab:>--,trail:·,extends:>,precedes:<,nbsp:·
    highlight Whitespace ctermfg=grey guifg=lightgrey
  endif
endfunction

" Map key to toggle the display of invisible characters
nnoremap <leader>i :call ToggleInvisibleChars()<CR>

set nowrap
