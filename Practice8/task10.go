func printTypes(data []interface{}) {
	for _, v := range data {
		if _, ok := v.(int); ok {
			fmt.Print("int ")
		} else if _, ok := v.(string); ok {
			fmt.Print("string ")
		} else if _, ok := v.(Human); ok {
			fmt.Print("Human ")
		} else if _, ok := v.(*Human); ok {
			fmt.Print("*Human ")
		} else {
			fmt.Print("interface ")
		}
	}
}
