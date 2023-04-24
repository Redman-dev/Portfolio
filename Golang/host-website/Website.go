package main

import (
	"html/template"
	"net/http"
)

var tpl *template.Template

func init() {
	tpl = template.Must(template.ParseGlob("./Files/Project.html"))
}

func main() {
	http.HandleFunc("/", index)
	fileServer := http.FileServer(http.Dir("./Files"))
	http.Handle("/Files/", http.StripPrefix("/Files", fileServer))

	http.ListenAndServe(":3000", nil)

}

func index(w http.ResponseWriter, r *http.Request) {
	tpl.ExecuteTemplate(w, "Project.html", nil)
}
