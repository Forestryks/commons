colorscheme peachpuff
set number relativenumber
set nu rnu
syntax on
set tabstop=4
set shiftwidth=4
set ai
set cin
set smartindent
set smarttab
set expandtab
set backspace=indent,eol,start
let c_no_curly_error=1
nmap <C-s> :w<CR>
imap <C-s> <Esc>:w<CR>
map <C-l> :tabnext<cr>
map <C-h> :tabprev<cr>
nmap <bs> :tabprev<cr>
map <C-t> :tabnew <cr>
map <C-w> :q <cr>
map Y y$

