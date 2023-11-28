type Cat struct {
	perem_is_alive int
}

type Box struct {
	cat Cat
}

func (cat Cat) is_alive() bool {
	return cat.perem_is_alive == 1
}

func (box Box) open() Cat {
	rand.Seed(time.Now().UnixNano())
	box.cat.perem_is_alive = rand.Int() % 2

	return box.cat
}
