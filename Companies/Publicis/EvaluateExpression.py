def evaluate_operator_args(operator: str, arg_list: list):
    if operator == "!":
        res = int(not int(arg_list[0]))
    elif operator == "&":
        res = int(arg_list[0]) & int(arg_list[1])
    elif operator == "|":
        res = int(arg_list[0]) | int(arg_list[1])
    # print(f"operator = {operator}, arg_list = {arg_list}, res = {res}")
    return res


def evaluate_expression(inp_str):
    st = []
    n = len(inp_str)
    operator = ""
    num_req_args = -1
    arg_list = []
    res = -1

    for i in range(n):
        if inp_str[i] in (" ", ","):
            continue
        elif inp_str[i] == "[":
            st.append((operator, num_req_args, arg_list))
        elif inp_str[i] == "]":
            while num_req_args == 0 and st:
                # print(f"evaluating at i = {i}")
                res = evaluate_operator_args(operator, arg_list)
                operator, num_req_args, arg_list = st.pop()
                num_req_args -= 1
                arg_list.append(res)
        elif inp_str[i] in "|&!":
            operator = inp_str[i]
            arg_list = []
            num_req_args = 1 if operator == "!" else 2
        else:
            arg_list.append(int(inp_str[i]))
            num_req_args -= 1

    # print(f"done for loop")
    # print(f"returning res = {res}")
    return res


inp_str = "[|, [&, 1, [!, 0]], [!, [|, 1, 0], [!, 1]]]]"
print(evaluate_expression(inp_str))