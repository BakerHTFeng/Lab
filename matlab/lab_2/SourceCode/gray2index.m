function index = gray2index( gray, n )
%GRAY2INDEX �Ҷ�ͼ��ת��Ϊ����ͼ��
%   ���Ҷ�ͼ��grayת����ɫ��Ϊn������ͼ��
    [x,y] = size(gray);
    index = zeros(x,y);
    for i = 1:x
        for j = 1:y
            index(i,j) = (gray(i,j) + 1)/floor(256/n) - 1;
        end
    end
end

