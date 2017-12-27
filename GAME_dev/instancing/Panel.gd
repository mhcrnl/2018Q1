extends Panel

# class member variables go here, for example:
# var a = 2
# var b = "textvar"

func _ready():
	# Called every time the node is added to the scene.
	# Initialization here
	get_node("Label/Button").connect("pressed",self,"_on_Button_pressed")


func _on_Button_pressed():
	 # replace with function body
	get_node("Label/Button").set_text("SALUT")
