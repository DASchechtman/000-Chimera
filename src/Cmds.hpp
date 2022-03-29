#pragma once

enum COMMANDS {
    NO_CMD,
    RAW_DATA_CMD,
    TRACK_TYPE_CMD,
    CHECK_SCOPE_CMD,
    CHECK_PARENT_SCOPE_CMD,
    OVERRIDE_SCOPE_CMD,
    MAKE_FUNC_CMD,
    CALL_FUNC_CMD,
    FUNC_RETR_CMD,
    FUNC_END_CMD,
    FUNC_PARAM_CMD,
    FUNC_SURO_TYPE,
    FUNC_FURO_TYPE,
    FUNC_FUNC_TYPE,
    BIND_CMD,
    REBIND_CMD,
    REBIND_REF_CMD,
    REFBIND_CMD,
    MAKE_UNION_CMD,
    MAKE_LIST_CMD,
    MAKE_MAP_CMD,
    PUT_IN_CONTAINER_CMD,
    PUT_IN_MAP_CMD,
    GET_FROM_CONTAINER_CMD,
    SET_IN_CONTAINER_CMD,
    REASSIGN_CONTAINER_CMD,
    GET_CONTAINER_SIZE_CMD,
    CLONE_TO_TEMP_CMD,
    ADDITION_CMD,
    INC_CMD,
    MOD_CMD,
    SUBTRACTION_CMD,
    MULTIPLY_CMD,
    DIVIDE_CMD,
    POW_CMD,
    CAST_TYPE_CMD,
    AND_CMD,
    OR_CMD,
    NOT_CMD,
    LESS_CMD,
    LESS_EQ_CMD,
    GREATER_CMD,
    GREATER_EQ_CMD,
    EQ_CMD,
    GARBAGE_COLLECT_CMD,
    CREATE_SCOPE_CMD,
    DESTROY_SCOPE_CMD,
    SET_NEXT_SCOPE_CMD,
    PRINT_CMD,
    CTRL_BLOCK_CMD,
    IF_BLOCK_CMD,
    ELIF_BLOCK_CMD,
    ELSE_BLOCK_CMD,
    WHILE_BLOCK_CMD,
    START_BLOCK_CMD,
    END_BLOCK_CMD,
    END_SCOPE_CMD
};