function result = gray_extension(A,min,max,k,b)
%GRAY_EXTENSION �Ҷ�����
% ������A�ڻҶȴ���(min,max)������ֵ��y = kx + b������������
    % p,qΪ����A�ĳ�����
    [p,q]=size(A);
    % result
    result = zeros(p,q);
    for i = 1:p
        for j = 1:q
            % ���Ҷȴ���(min.max)�����죬������ԭ�Ҷ�ֵ
            if A(i,j) < max && A(i,j) > min
                result(i,j) = (A(i,j) * k) + b;
            else
                result(i,j) = A(i,j);
            end
        end
    end
end

