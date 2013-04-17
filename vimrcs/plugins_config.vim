"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Important: 
"       This requries that you install https://github.com/amix/vimrc !
"
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


""""""""""""""""""""""""""""""
" => pathogen paths {{{1
""""""""""""""""""""""""""""""
call pathogen#infect('~/.vim_runtime/plugins')
call pathogen#helptags()

""""""""""""""""""""""""""""""
" => bufExplorer {{{1
""""""""""""""""""""""""""""""
let g:bufExplorerDefaultHelp=0
let g:bufExplorerShowRelativePath=1
let g:bufExplorerFindActive=1
let g:bufExplorerSortBy='name'
map <leader>o :BufExplorer<cr>


""""""""""""""""""""""""""""""
" => CTRL-P {{{1
""""""""""""""""""""""""""""""
let g:ctrlp_working_path_mode = 0

let g:ctrlp_map = '<c-f>'
map <c-b> :CtrlPBuffer<cr>

let g:ctrlp_max_height = 20
let g:ctrlp_custom_ignore = 'node_modules\|^\.DS_Store\|^\.git\|^\.coffee'

""""""""""""""""""""""""""""""
" => snipMate (beside <TAB> support <CTRL-j>) {{{1
""""""""""""""""""""""""""""""
ino <c-j> <c-r>=snipMate#TriggerSnippet()<cr>
snor <c-j> <esc>i<right><c-r>=snipMate#TriggerSnippet()<cr>


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Nerd Tree {{{1
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let NERDTreeWinPos="right"
let NERDTreeMouseMode=2
map <F12> :NERDTreeToggle<cr>
map <leader>nb :NERDTreeFromBookmark 
map <leader>nf :NERDTreeFind<cr>


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => surround  {{{1
" Annotate strings with gettext http://amix.dk/blog/post/19678
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
vmap Si S(i_<esc>f)
au FileType mako vmap Si S"i${ _(<esc>2f"a) }<esc>



"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Taglist {{{1
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"let Tlist_Show_One_File=1
"let Tlist_Auto_Open =0 
"let Tlist_Exit_OnlyWindow = 1
"let Tlist_Use_Right_Window = 0
"let Tlist_File_Fold_Auto_Close=1
"let Tlist_Show_Menu=0
"map <leader>tt :TlistToggle<cr><cr>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Tagbar {{{1
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:tagbar_left=1
let g:tagbar_autoclose=0
let g:tagbar_compact=1
let g:tagbar_iconchars = ['+', '-']
map <F2> :TagbarToggle<cr><cr>


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => PowerLine {{{1
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"let g:Powerline_symbols = 'compatible'
"let g:Powerline_symbols = 'unicode'
let g:Powerline_symbols = 'fancy'
set fillchars+=stl:\ ,stlnc:\ 
let g:Powerline_cache_enabled = 1
set laststatus=2
set t_Co=256
set nocompatible


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Syntastic {{{1
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"let g:syntastic_check_on_open=1;


" vim: ts=8 sw=4 sts=4 et foldenable foldmethod=marker foldcolumn=1
