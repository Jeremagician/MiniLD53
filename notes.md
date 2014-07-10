# Notes #
## Utile ##
Commande *multi plate-forme* pour convertir tout les *.xcf du dossier en png.
Pratique pour de l'output d'assets automatisé.

```sh
gimp -n -i -b - <<EOF
(let* ( (file's (cadr (file-glob "*.xcf" 1))) (filename "") (image 0) (layer 0) )
  (while (pair? file's)
    (set! image (car (gimp-file-load RUN-NONINTERACTIVE (car file's) (car file's))))
    (set! layer (car (gimp-image-merge-visible-layers image CLIP-TO-IMAGE)))
    (set! filename (string-append (substring (car file's) 0 (- (string-length (car file's)) 4)) ".png"))
    (gimp-file-save RUN-NONINTERACTIVE image layer filename filename)
    (gimp-image-delete image)
    (set! file's (cdr file's))
    )
  (gimp-quit 0)
  )
EOF
```

## Tricks ##
### scope(exit) C++11 ###

```c++
template <typename F>
struct ScopeExit {
	ScopeExit(F f) : f(f) {}
	~ScopeExit() { f(); };
	F f;
};

// On utilise MakeScopeExit pour ne pas avoir
// à préciser le type du template (implicite ...)
template <typename F>
ScopeExit<F> MakeScopeExit(F f) {
	return ScopeExit<F>(f);
};

// Preprocessor concat, nx means non expanded
#define PPCAT_NX(arg1, arg2) arg1 ## arg2
#define PPCAT(arg1, arg2) PPCAT_NX(arg1, arg2)

#define SCOPE_EXIT(code) \
	auto PPCAT(scope_exit_,__LINE__) = MakeScopeExit([=](){code;})

```
Une choise à savoir :
En C++ la destruction se fait dans le sens inverse des déclarations.

reference : http://the-witness.net/news/2012/11/scopeexit-in-c11/
