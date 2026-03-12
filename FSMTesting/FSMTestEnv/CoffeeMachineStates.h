#pragma once

// --- States (to be managed by FSM later) ---
enum MachineState {
    IDLE,
    LOW_WATER,
    LOW_BEANS,
    BREWING,
    CLEANING,
    NEEDS_CLEANING,
    MAX
};
