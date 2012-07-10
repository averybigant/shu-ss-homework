if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <S-Tab> =BackwardsSnippet()
inoremap <silent> <Plug>NERDCommenterInInsert  <BS>:call NERDComment(0, "insert")
snoremap <silent> 	 i<Right>=TriggerSnippet()
snoremap  b<BS>
snoremap % b<BS>%
snoremap ' b<BS>'
vmap T <Plug>TranslateBlockText
snoremap U b<BS>U
vmap [% [%m'gv``
snoremap \ b<BS>\
nmap <silent> \cr <Plug>CRV_CRefVimNormal
vmap <silent> \cr <Plug>CRV_CRefVimVisual
nmap \ihn :IHN
nmap \is :IHS:A
nmap \ih :IHS
nmap \ca <Plug>NERDCommenterAltDelims
vmap \cA <Plug>NERDCommenterAppend
nmap \cA <Plug>NERDCommenterAppend
vmap \c$ <Plug>NERDCommenterToEOL
nmap \c$ <Plug>NERDCommenterToEOL
vmap \cu <Plug>NERDCommenterUncomment
nmap \cu <Plug>NERDCommenterUncomment
vmap \cn <Plug>NERDCommenterNest
nmap \cn <Plug>NERDCommenterNest
vmap \cb <Plug>NERDCommenterAlignBoth
nmap \cb <Plug>NERDCommenterAlignBoth
vmap \cl <Plug>NERDCommenterAlignLeft
nmap \cl <Plug>NERDCommenterAlignLeft
vmap \cy <Plug>NERDCommenterYank
nmap \cy <Plug>NERDCommenterYank
vmap \ci <Plug>NERDCommenterInvert
nmap \ci <Plug>NERDCommenterInvert
vmap \cs <Plug>NERDCommenterSexy
nmap \cs <Plug>NERDCommenterSexy
vmap \cm <Plug>NERDCommenterMinimal
nmap \cm <Plug>NERDCommenterMinimal
vmap \c  <Plug>NERDCommenterToggle
nmap \c  <Plug>NERDCommenterToggle
vmap \cc <Plug>NERDCommenterComment
nmap \cc <Plug>NERDCommenterComment
vmap ]% ]%m'gv``
snoremap ^ b<BS>^
snoremap ` b<BS>`
vmap a% [%v]%
nmap gx <Plug>NetrwBrowseX
map <C-F5> :!gcc -Wall -g % -lm;echo "Done"
map <F5> :!gcc -Wall % -lm;echo "Done"
map <F12> :!./a.out
snoremap <Left> bi
snoremap <Right> a
snoremap <BS> b<BS>
snoremap <silent> <S-Tab> i<Right>=BackwardsSnippet()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
vnoremap <silent> <Plug>TranslateBlockText :call GoogTranslateBlock()
nnoremap <silent> <Plug>TranslateBlockText :call GoogTranslateBlock()
nnoremap <silent> <F11> :call conque_term#exec_file()
nmap <silent> <Plug>NERDCommenterAppend :call NERDComment(0, "append")
nnoremap <silent> <Plug>NERDCommenterToEOL :call NERDComment(0, "toEOL")
vnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment(1, "uncomment")
nnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment(0, "uncomment")
vnoremap <silent> <Plug>NERDCommenterNest :call NERDComment(1, "nested")
nnoremap <silent> <Plug>NERDCommenterNest :call NERDComment(0, "nested")
vnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment(1, "alignBoth")
nnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment(0, "alignBoth")
vnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment(1, "alignLeft")
nnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment(0, "alignLeft")
vmap <silent> <Plug>NERDCommenterYank :call NERDComment(1, "yank")
nmap <silent> <Plug>NERDCommenterYank :call NERDComment(0, "yank")
vnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment(1, "invert")
nnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment(0, "invert")
vnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment(1, "sexy")
nnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment(0, "sexy")
vnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment(1, "minimal")
nnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment(0, "minimal")
vnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment(1, "toggle")
nnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment(0, "toggle")
vnoremap <silent> <Plug>NERDCommenterComment :call NERDComment(1, "norm")
nnoremap <silent> <Plug>NERDCommenterComment :call NERDComment(0, "norm")
inoremap <silent> 	 =TriggerSnippet()
inoremap <silent> 	 =ShowAvailableSnips()
imap \ihn :IHN
imap \is :IHS:A
imap \ih :IHS
let &cpo=s:cpo_save
unlet s:cpo_save
set autochdir
set autoindent
set background=dark
set backspace=indent,eol,start
set complete=.,w,b,k
set completeopt=longest,menuone
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=cn
set printoptions=paper:a4
set ruler
set runtimepath=~/.vim/bundle/vundle,~/.vim/bundle/The-NERD-Commenter,~/.vim/bundle/The-NERD-tree,~/.vim/bundle/AutoComplPop,~/.vim/bundle/snipMate,~/.vim/bundle/NERD_tree-Project,~/.vim/bundle/Conque-Shell,~/.vim/bundle/clang-complete,~/.vim/bundle/a.vim,~/.vim/bundle/CRefVim,~/.vim/bundle/pydoc.vim,~/.vim/bundle/pyflakes,~/.vim/bundle/taglist.vim,~/.vim/bundle/Pydiction,~/.vim/bundle/python_fold,~/.vim/bundle/matchit.zip,~/.vim/bundle/html5.vim,~/.vim/bundle/HTML5-Syntax-File,~/.vim/bundle/vim-translator,~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after,~/.vim/bundle/vundle/,~/.vim/bundle/shucg/,~/.vim/bundle/pysyntax/,~/.vim/bundle/javascriptsyntax/,~/.vim/bundle/vundle/after,~/.vim/bundle/The-NERD-Commenter/after,~/.vim/bundle/The-NERD-tree/after,~/.vim/bundle/AutoComplPop/after,~/.vim/bundle/snipMate/after,~/.vim/bundle/NERD_tree-Project/after,~/.vim/bundle/Conque-Shell/after,~/.vim/bundle/clang-complete/after,~/.vim/bundle/a.vim/after,~/.vim/bundle/CRefVim/after,~/.vim/bundle/pydoc.vim/after,~/.vim/bundle/pyflakes/after,~/.vim/bundle/taglist.vim/after,~/.vim/bundle/Pydiction/after,~/.vim/bundle/python_fold/after,~/.vim/bundle/matchit.zip/after,~/.vim/bundle/html5.vim/after,~/.vim/bundle/HTML5-Syntax-File/after,~/.vim/bundle/vim-translator/after
set showcmd
set smartindent
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set switchbuf=useopen
set tags=./tags,./TAGS,tags,TAGS,~/.vim/c_systags,~/.vim/py_tags
set wildmenu
" vim: set ft=vim :
