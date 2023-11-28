type Water struct {
	temperature int
}

type Teapot struct {
	water Water
}

func NewTeapot(water *Water) *Teapot {
	return &Teapot{*water}
}

func NewWater(temperature int) *Water {
	return &Water{temperature}
}

func (teapot *Teapot) is_boiling() bool {
	return teapot.water.temperature >= 100
}

func (teapot *Teapot) heat_up(temp_up int) {
	teapot.water.temperature += temp_up
}
