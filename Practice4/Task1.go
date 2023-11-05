package main

//map[<type>]interface — любые значения при строковых ключах
// Поля структуры, которую сереализуем, должны начинаться с заглавной буквы. Иначе неэкспортируемые.
// Можно указать тег (псевдоним) `json: "name"`
// Если закодировать указатели, в json поместятся их значения

import (
	"encoding/json"
	"fmt"
	"os"
)

type Task struct {
	User_id   int    `json: "user_id"`
	Id        int    `json: "id"`
	Title     string `json: "tutle"`
	Completed bool   `json:"completed"`
}

type Project struct {
	Project_id int    `json: "project_id"`
	Tasks      []Task `json: "tasks"`
}

func main() {
	file, err := os.ReadFile("data.json")

	if err != nil {
		fmt.Println("Error1: ", err)
		os.Exit(1)
	}

	var data []Project
	json.Unmarshal([]byte(file), &data)

	var find_user_id int
	fmt.Scan(&find_user_id)

	cnt := 0

	for i := 0; i < len(data); i++ {
		for k := 0; k < len(data[i].Tasks); k++ {
			if data[i].Tasks[k].User_id == find_user_id && data[i].Tasks[k].Completed == true {
				cnt++
			}
		}
	}

	fmt.Print(cnt)
}
