package main

import (
	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/app"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/widget"
	"image/color"
)

func main() {
	a := app.New()
	w := a.NewWindow("In Class Exercise 4")
	w.Resize(fyne.NewSize(700, 700))
	circle1 := canvas.NewCircle(color.NRGBA{R: 0, G: 0, B: 0, A: 255})
	circle1.StrokeColor = color.Black
	circle1.StrokeWidth = 3
	redbtn := widget.NewButton("RED", func() {
		circle1.FillColor = color.NRGBA{R: 255, G: 0, B: 0, A: 255}
		circle1.Refresh()
	})
	yellowbtn := widget.NewButton("YELLOW", func() {
		circle1.FillColor = color.NRGBA{R: 255, G: 255, B: 0, A: 255}
		circle1.Refresh()
	})
	greenbtn := widget.NewButton("GREEN", func() {
		circle1.FillColor = color.NRGBA{R: 0, G: 255, B: 0, A: 255}
		circle1.Refresh()
	})
	content := container.NewGridWithRows(4)
	content.Add(circle1)
	content.Add(greenbtn)
	content.Add(yellowbtn)
	content.Add(redbtn)
	w.SetContent(content)
	w.ShowAndRun()
}
