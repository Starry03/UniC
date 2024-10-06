package main

import (
	"database/sql"
	"fmt"
	"log"
	"os"

	"github.com/joho/godotenv"
	"github.com/labstack/echo/v4"
	_ "github.com/lib/pq"
)

type function_s struct {
	category string
	name     string
	header   string
	body     string
	doc      string
}

func query_search_match(userInput string, db *sql.DB) *sql.Rows {
	query_string := "SELECT * FROM functions.function WHERE name ~ $1"
	res, err := db.Query(query_string, "^"+userInput)
	if err != nil {
		log.Fatal(err)
	}
	return res
}

func init_db() *sql.DB {
	err := godotenv.Load()
	if err != nil {
		log.Fatal("Error loading .env file")
	}
	dbname := os.Getenv("POSTGRES_DB")
	username := os.Getenv("POSTGRES_USER")
	password := os.Getenv("POSTGRES_PASSWORD")
	host := os.Getenv("POSTGRES_HOST")
	port := os.Getenv("POSTGRES_PORT")
	conn := fmt.Sprintf("user=%s password=%s dbname=%s host=%s port=%s sslmode=disable", username, password, dbname, host, port)
	db, err := sql.Open("postgres", conn)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Connected to database")
	return db
}

func main() {
	db := init_db()
	e := echo.New()
	e.POST("/queryFunctions/:userInput", func(c echo.Context) error {
		var matches *sql.Rows = query_search_match(c.Param("userInput"), db)
		var functions_name []string
		for matches.Next() {
			var function function_s
			err := matches.Scan(&function.category, &function.name, &function.header, &function.body, &function.doc)
			if err != nil {
				log.Fatal(err)
			}
			functions_name = append(functions_name, function.name)
		}
		return c.JSON(200, functions_name)
	})
	e.Logger.Fatal(e.Start("localhost:1323"))
}
