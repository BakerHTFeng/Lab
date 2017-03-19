function result = hist_equal( img )
%HIST_EQUAL ֱ��ͼ���⻯
%   ��img���⻯���ֱ��ͼ
    [x,y] = size(img);
    per = zeros(256);
    cum = zeros(256);
    result = zeros(x,y);
    % ͳ�Ƹ��Ҷȳ��ִ���
    for i = 0 : 255
        per(i + 1) = numel(find(img == (i)));
    end
    % ������ռ����
    per = per/(x * y * 1.0);
    % �����ۻ��ֲ�����
    for i = 2: 256
        cum(i) = cum(i-1) + per(i);
    end
    % �������ĻҶ�ֵ
    for i = 1: x
        for j = 1:y
            result(i,j) = round(256.0 * cum(double(img(i,j)) + 1));
        end
    end
    result = uint8(result);
end