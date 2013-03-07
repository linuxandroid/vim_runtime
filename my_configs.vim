"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => UI setting modify.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set so=0    "source line
set mouse=a
set foldcolumn=0
set mousemodel=popup

" highlight current line
au WinLeave * set nocursorline nocursorcolumn
au WinEnter * set cursorline cursorcolumn
set cursorline cursorcolumn


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Color scheme setting.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
color peaksea
"color default


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => CSCOPE
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set cscopequickfix=s-,c-,d-,i-,t-,e-
if has("cscope")
        set csprg=/usr/bin/cscope
        set csto=0
        set cst
        set nocsverb
        " add any database in current directory
        if filereadable("cscope.out")
            cs add cscope.out
        " else add database pointed to by environment
        elseif $CSCOPE_DB != ""
            cs add $CSCOPE_DB
        endif
        set csverb
endif

nmap <C-_>s :cs find s <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>g :cs find g <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>c :cs find c <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>t :cs find t <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>e :cs find e <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
nmap <C-_>i :cs find i <C-R>=expand("<cfile>")<CR><CR>
nmap <C-_>d :cs find d <C-R>=expand("<cword>")<CR><CR>





