#include <core/config11/cfg11.h>
#include <core/int/int.h>
#include <core/mm/slab.h>
#include <drivers/i2c.h>
#include <shared/lib/print.h>
#include <shared/display/fb.h>
#include <shared/types.h>
#include <core/communication/arm9.h>

void main(void)
{
	fb_clear();
	ivt_init();

	u8 *top_display_fb = (u8 *)0x18300000; // temporary!!!
	fillrect(top_display_fb, 0xFFF224, 40, 50, 50, 125);

	print("Booted on a %s", cfg11_get_console_name());

	// Todo: This sucks, would need to be an interrupt in the future
	bool set_operation = false;
	while (true)
	{
		const Arm9Message msg = handle_message();
		if (msg != NONE && !set_operation)
		{
			print("Received a message! %d", msg);
			set_operation = true;
		}
	}

	// i2c_write(3, 0x20, 1 << 0); // shutdown

	for (;;)
		;
}