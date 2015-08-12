#ifndef USER_ACTION
#define USER_ACTION

enum UserActionType {
	MOUSE_OVER = 0,
	MOUSE_CLICK_OVER
};

struct UserAction {
	UserActionType type;
	int bidon;
};

#endif