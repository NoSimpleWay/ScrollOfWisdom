#include "EWindowMain.h"

EWindowMain::EWindowMain()
{

	button_array_collection_massive* jc_massive = new button_array_collection_massive(this);
	button_array_collection_massive_list.push_back(jc_massive);
	*jc_massive->size_x = 600.0f;
	*jc_massive->size_y = 300.0f;

	button_array_horizontal_collection* jc_horizontal_collection = new button_array_horizontal_collection(5.0f, 5.0f, 100.0f, 25.0f);
	//*jc_massive->size_y = 300.0f;
	jc_massive->button_array_horizontal_collection_list.push_back(jc_horizontal_collection);

	button_array_vertical_collection* jc_vertical_collection = new button_array_vertical_collection(5.0f, 5.0f, 100.0f, 25.0f);
	jc_horizontal_collection->button_array_vertical_collection_list.push_back(jc_vertical_collection);
	*jc_vertical_collection->selected_distance_between_button_mode = button_array_vertical_collection::BUTTON_DISTANCE_ALIGN_RULE::FREE;

	button_array* jc_button_array = new button_array;
	jc_vertical_collection->button_array_list.push_back(jc_button_array);
	//jc_button_array->

	EButton*
	but = new EButton(0.0f, 0.0f, 200.0f, 15.0f);
	but->text = "Righterious fire";
		but->master_window = this;
		jc_button_array->button_list.push_back(but);

	but = new EButton(500.0f, 0.0f, 200.0f, 15.0f);
		but->master_window = this;
		jc_button_array->button_list.push_back(but);

}

EWindowMain::~EWindowMain()
{
}
