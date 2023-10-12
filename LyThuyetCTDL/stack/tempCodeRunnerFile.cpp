    while (!IsEmpty(src)) {
        int topValue = src.nodes[src.top];
        src.top--; // Giảm top để loại bỏ phần tử từ stack gốc
        Push(temp, topValue); // Đẩy giá trị vào stack tạm thời
    }