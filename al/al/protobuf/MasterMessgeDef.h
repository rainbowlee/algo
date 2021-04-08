#pragma once
enum R2D_EVENT
{
	R2D_EVENT_BASE = 5000,
	R2D_DrdPrepareBattleRoom,		//^Drd^DrdPrepareBattleRoom#
	R2D_DrdRegisterDSServerResult,		//^Drd^DrdRegisterDSServerResult#
	R2D_DrdHeartBeat,		//^Drd^DrdHeartBeat#
	R2D_DrdBattleEnd,		//^Drd^DrdBattleEnd#
	R2D_EVENT_BASE_LUA = 5100,
	R2D_EVENT_MAX,
};
enum D2R_EVENT
{
	D2R_EVENT_BASE = 6000,
	D2R_DdrPrepareBattleRoomResult,		//^Ddr^DdrPrepareBattleRoomResult#
	D2R_DdrRegisterDSServer,		//^Ddr^DdrRegisterDSServer#
	D2R_DdrHeartBeat,		//^Ddr^DdrHeartBeat#
	D2R_DdrBattleEnd,		//^Ddr^DdrBattleEnd#
	D2R_EVENT_BASE_LUA = 6100,
	D2R_EVENT_MAX,
};