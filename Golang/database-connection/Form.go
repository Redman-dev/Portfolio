package main

import (
	"database/sql"
	"fmt"
	_ "github.com/lib/pq"
	"html/template"
	"net/http"
)

const (
	host     = "localhost"
	port     = 5432
	user     = "postgres"
	password = "123"
	dbname   = "InClassExercise5"
)

func main() {
	psqlconn := fmt.Sprintf("host=%s port =%d user = %s password = %s dbname = %s sslmode = disable", host, port, user, password, dbname)

	db, err := sql.Open("postgres", psqlconn)
	checkError(err)
	defer db.Close()
	http.HandleFunc("/", getRoute)
	http.HandleFunc("/hi", postRoute)
	http.ListenAndServe(":3000", nil)
}

func getRoute(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		var tmpl = template.Must(template.New("form").ParseFiles("form.html"))
		tmpl.Execute(w, nil)
		return
	}

}

func postRoute(w http.ResponseWriter, r *http.Request) {

	if r.Method == http.MethodPost {
		tmpl := template.Must(template.New("result").ParseFiles("form.html"))
		psqlconn := fmt.Sprintf("host=%s port =%d user = %s password = %s dbname = %s sslmode = disable", host, port, user, password, dbname)

		db, err := sql.Open("postgres", psqlconn)
		checkError(err)
		defer db.Close()
		insertStmt := `insert into public."Employees"("EmployeeName", "EmployeeAddress", "MonthSalary", "PhoneNo")values('` +
			r.FormValue("name") + `', '` + r.FormValue("address") + `', '` + r.FormValue("salary") + `', '` + r.FormValue("phone") + (`')`)
		_, e := db.Exec(insertStmt)
		checkError(e)
		tmpl.Execute(w, nil)
		return
	}
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}
