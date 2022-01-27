/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	GIE				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"
#include "GIE_config.h"
#include "GIE_private.h"


void GIE_VoidEnable (void)
{
	SET_BIT(SREG,SREG_I_BIT);
}


void GIE_VoidDisable (void)
{
	CLR_BIT(SREG,SREG_I_BIT);
}