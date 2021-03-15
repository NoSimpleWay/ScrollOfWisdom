#pragma once





#include <glad/glad.h>
#include <GLFW/glfw3.h>


//glm::mat4 matrix_transform;

#include "NSW_api/Batcher.h"
#include <vector>
#include "NSW_api/EFont.h"



#include <iostream>
#include <chrono>

#include "NSW_api/ETextureAtlas.h"

#include "NSW_api/EUtils.h"
#include <windows.h>

//#include <WinUser.h>

//#include "NSW_api/EWindowTest.h"

class EWindowMain;
class EButton;


class EWindow
{
public:
	void default_update(float _d);
	virtual void update(float _d);

	void default_draw(float _d);
	virtual void draw(float _d);

	void default_resize_event();


	virtual void draw_interface(float _d);
	void default_draw_interface(float _d);

	void static add_time_process(std::string _name);

	static GLFWwindow* main_window;

	static unsigned int transformLoc;

	float offset_x = 0;
	float offset_y = 0;

	float position_x = 0;
	float position_y = 0;
	
	float window_size_x = 100.0f;
	float window_size_y = 100.0f;

	static double mouse_x;
	static double mouse_y;
	
	static int prev_mouse_x;
	static int prev_mouse_y;

	static int saved_pos_x;
	static int saved_pos_y;

	static float mouse_speed_x;
	static float mouse_speed_y;

	static float real_mouse_x;
	static float real_mouse_y;

	static bool LMB;
	static bool RMB;

	static bool system_button_release;

	static double scroll;

	//static std::pair<float, std::string> time_process;

	struct time_process_struct
	{
		std::vector<float> time_process_value;
		std::string time_process_name;
	};

	static std::vector<time_process_struct*> tps_list;

	static int time_process_rota_id;
	static std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;

	static void push_cursor(float _x, float _y);

	EWindow();
	~EWindow();

	static Batcher* batch;
	static std::vector<EWindow*> window_list;
	static float delete_button_hold_time;

	static EWindowMain* window_main;

	static ETextureAtlas* default_texture_atlas;
	static ETextureAtlas* shadow_FBO;
	static ETextureAtlas* shadow_ground_FBO;
	static ETextureAtlas* lightmap_FBO;
	static ETextureAtlas* lightmap_FBO2;
	static ETextureAtlas* base_lightmap;
	static ETextureAtlas* base_blockmap;

	static ETextureAtlas* screen_FBO;

	static bool button_pressed;

	static bool button_main_group_pressed;

	static bool button_right_pressed;
	static bool button_backspace_released;
	bool is_active = true;
	int id = 0;

	static bool is_overlap(EWindow* _w);

	static char last_inputed_char;

	std::vector <EButton*> button_list;
	std::vector <EButton*> default_button_list;

	bool always_fullscreen;
	bool have_bg = false;

	bool screen_space = false;

	EGabarite* screen_space_texture = NULL;

	int align_x;
	int align_y;

	struct button_array
	{
		std::vector <EButton*> button_list;

		float* maximum_size_x = new float(0.0f);

		float* position_x = new float(0.0f);
		float* position_y = new float(0.0f);

		float* size_x = new float(0.0f);
		float* size_y = new float(0.0f);


	};

	struct button_array_vertical_collection
	{
		button_array_vertical_collection(float _x, float _y, float _sx, float _sy)
		{
			*position_x = _x;
			*position_y = _y;

			*size_x = _sx;
			*size_y = _sy;
		}

		int* tab_id = new int(0);
		int* maximum_button_on_array = new int(0);

		enum BUTTON_DISTANCE_ALIGN_RULE
		{
			FREE,
			BUTTON_SIZE,
			MAXIMUM_BUTTON_SIZE
		};

		int* selected_distance_between_button_mode = new int(BUTTON_DISTANCE_ALIGN_RULE::FREE);

		float* additional_horisontal_distance_between_buttons = new float(0.0f);
		float* additional_vertical_distance_between_buttons = new float(0.0f);

		float* position_x = new float(0.0f);
		float* position_y = new float(0.0f);

		float* size_x = new float(0.0f);
		float* size_y = new float(0.0f);

		std::vector <button_array*> button_array_list;

		//std::vector<EButton*> a;

		static void update_button_position()
		{

		}


	};

	struct button_array_horizontal_collection
	{

		button_array_horizontal_collection(float _x, float _y, float _sx, float _sy)
		{
			*position_x = _x;
			*position_y = _y;

			*size_x = _sx;
			*size_y = _sy;
		}

		int* selected_tab = new int(0);
		
		struct test
		{

		};

		float* position_x = new float(0.0f);
		float* position_y = new float(0.0f);
		
		float* size_x = new float(0.0f);
		float* size_y = new float(0.0f);

		std::vector < button_array_vertical_collection*> button_array_vertical_collection_list;

		std::vector <EButton*> tab_button_list;

		int* push_method = new int(ARRAY_PUSH_METHOD::APM_PUSH_Y);
		
	};

	enum ARRAY_PUSH_METHOD
	{
		APM_NONE,
		APM_PUSH_X,
		APM_PUSH_Y
	};

	struct button_array_collection_massive
	{
		bool* head_catched = new bool(false);
		bool* catch_highlight = new bool(false);
		button_array_collection_massive(EWindow* _w);

		bool* is_active = new bool (true);

		std::vector < button_array_horizontal_collection* > button_array_horizontal_collection_list;

		float* position_x = new float(0.0f);
		float* position_y = new float(0.0f);
		//-
		float* size_x = new float(0.0f);
		float* size_y = new float(0.0f);

		std::vector<EButton*> service_button;

		EButton* button_close = NULL;

		int* selected_style = new int(0);
	};

	enum GabariteBackgroundMode
	{
		//
		//non screen space
		//
		GBM_SIMPLE,

		//
		//screen space
		//
		GBM_SCREEN_SPACE
	};
	struct massive_style
	{
		EGabarite* left_corner		= NULL;
		EGabarite* right_corner		= NULL;
		EGabarite* up_corner		= NULL;
		EGabarite* down_corner		= NULL;

		EGabarite* LU_corner		= NULL;
		EGabarite* RU_corner		= NULL;
		EGabarite* LD_corner		= NULL;
		EGabarite* LR_corner		= NULL;

		EGabarite* background		= NULL;

		int background_mode			= GabariteBackgroundMode::GBM_SCREEN_SPACE;


		

	};

	static std::vector <massive_style*> list_of_massive_style;

	std::vector<button_array_collection_massive*> button_array_collection_massive_list;


	//void draw_lightmap();

};

class EButton
{
public:
	typedef void (*BUTTON_ACTION)(EButton* _b, float _d);

	BUTTON_ACTION action_on_left_click;

	BUTTON_ACTION action_on_left_double_click;
	float* click_timer = new float(0.0f);

	BUTTON_ACTION action_on_right_click;

	BUTTON_ACTION action_on_input;
	BUTTON_ACTION action_on_input_finish;

	BUTTON_ACTION action_on_slider_drag;
	BUTTON_ACTION action_on_drop_list_select_element;

	
	int * target_address_for_int;
	int* target_value_for_int = new int(0);

	float * target_address_for_float;
	float * target_value_for_float = new float (0.0f);

	bool* target_address_for_bool;
	bool* target_value_for_bool = new bool(false);

	short* target_address_for_short;
	short* target_value_for_short = new short(1);

	EGabarite** target_address_for_gabarite;

	std::string* target_address_for_string;
	std::string* target_value_for_string = new std::string("");

	static void static_click();
	static void static_click2();

	static void set_left_click_action(void(*function)(EButton*, float));

	float button_x = 10;
	float button_y = 200;

	float button_base_x = 200;
	float button_base_y = 200;

	float button_size_x = 100;
	float button_size_y = 25;

	float button_min_size_x = 100;
	float button_min_size_y = 25;

	std::string text = "";

	bool have_input_mode = false;
	bool is_input_mode_active = false;

	bool is_active = true;
	bool icon_adaptation = true;

	float bound_size_left = 0;
	float bound_size_right = 0;
	float bound_size_up = 0;
	float bound_size_down = 0;

	bool is_expanded = false;
	bool is_drop_list = false;

	int master_position = Enums::PositionMaster::WINDOW;

	int drop_elements = 0;
	std::vector<string> drop_text;
	std::vector<string> drop_text_base;
	bool have_list_color = false;
	std::vector<EColor*> drop_list_color;

	bool slider_activate = false;

	EGabarite* gabarite = NULL;

	bool have_icon = false;
	EColor* icon_color = new EColor(1.0f, 1.0f, 1.0f, 1.0f);

	int position_mode_x = Enums::PositionMode::LEFT;
	int position_mode_y = Enums::PositionMode::DOWN;

	int text_align_x = Enums::PositionMode::LEFT;

	EWindow* master_window;
	EButton* master_button;


	float master_position_x = 0;
	float master_position_y = 0;

	EButton();
	EButton(float _x, float _y, float _sx, float _sy);
	//EButton(float _x, float _y, float _sx, float _sy, Enums::ButtonType _type);

	bool have_description = true;
	string description_text;
	string prev_description_text;

	bool have_text = true;

	string input_hint;



	~EButton();

	bool is_number(char _c);

	bool is_overlap();
	bool is_click();
	bool is_outclick();
	bool is_right_click();
	bool have_bg = true;
	void update(float _d);
	virtual void update_additional(float _d);

	bool is_holdable = false;

	bool is_slider = false;
	float slider_value;
	float slider_value_multiplier = 1.0f;

	virtual void additional_draw(Batcher* _batch, float _d);
	void default_draw(Batcher* _batch, float _d);


	void text_pass(Batcher* _batch);
	//virtual void incoming_data(FilterBlock* _block);

	bool outclick_protection = false;

	virtual void click_event();
	virtual void right_click_event();
	virtual void input_event();
	virtual void input_finish_event();
	virtual void drop_list_select_event();

	virtual void slider_drag_event();


	static int top_window_id;

	bool flash_line_active = false;
	float flash_cooldown = 0.5f;

	bool can_be_removed = false;
	bool* need_remove = new bool(false);

	bool have_rama = false;
	int rama_thikness = 2;
	EColor* rama_color = new EColor(0.0f, 0.0f, 0.0f, 1.0f);
	EColor* bg_color = new EColor(0.8f, 0.8f, 0.8f, 0.75f);
	EColor* text_color = new EColor(0.0f, 0.0f, 0.0f, 1.0f);

	int catched_element = 0;
	int selected_element = 0;

	//Enums::ButtonType button_type;

	bool input_only_numbers = false;

	int data_id;

	EColor* icon_color_default = new EColor(1.0f, 1.0f, 1.0f, 1.0f);
	EColor* icon_color_deactivated = new EColor(0.5f, 0.5f, 0.5f, 0.5f);

	EColor* rama_color_default = new EColor(1.0f, 1.0f, 1.0f, 1.0f);
	EColor* rama_color_deactivated = new EColor(0.5f, 0.5f, 0.5f, 0.5f);

	EColor* bg_color_default = new EColor(0.5f, 0.5f, 0.5f, 0.25f);
	EColor* bg_color_deactivated = new EColor(0.1f, 0.1f, 0.1f, 0.1f);

	void activate();
	void deactivate();

	bool dynamic_input_width = true;

	std::string data_string;

	bool slider_is_horizontal = true;

	virtual void update_localisation();



	bool input_auto_clear_text = false;

	EFont* force_font;

	//FilterBlockSeparator* master_separator;

	bool can_receive_paste = false;

	EWindow* simple_action_open_window;

	std::string* side_text = new string("");

	/*
	EButtonAction* button_action_press;
	EButtonAction* button_action_right_press;
	EButtonAction* button_action_input_finish;
	EButtonAction* button_action_outclick;*/


	//bool& link_to_boolean;

	

	static EButton* clone_button(EButton* _b, float _x, float _y, float _sx, float _sy);

	bool* double_click_started = new bool (false);
	bool* is_double_click = new bool (false);

	static bool any_input;
	static bool any_overlap;

	bool* is_consumable = new bool(false);
	bool* is_radial_button = new bool(false);
	float* maximum_value = new float (1.0f);

	bool* is_checkbox = new bool(false);
	bool* is_checked = new bool(false);
};

class EButtonGroup
{
public:

	
};

/*
class EDataWatcher
{
public:

	struct data_watch_float
	{
		float* data_value = new float(0.0f);
		std::string name;
	};

	struct data_watch_int
	{
		int* data_value = new int(0);
		std::string name;
	};

};*/

