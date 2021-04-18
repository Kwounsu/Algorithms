import re


def solution(word, pages):
    def find_index(tag):
        first_i = end_i = -1
        for idx, char in enumerate(tag):
            if char == '"':
                if first_i == -1:
                    first_i = idx + 1
                elif end_i == -1:
                    end_i = idx
        return first_i, end_i

    meta_parser = re.compile('<meta(.+?)/>')
    a_parser = re.compile('<a(.+?)>')
    page_infos = []

    for page in pages:
        a_tags = a_parser.findall(page)
        outer_url = []
        for a_tag in a_tags:
            first_idx, end_idx = find_index(a_tag)
            outer_url.append(a_tag[first_idx:end_idx])

        meta_tag = meta_parser.search(page).group()
        content_prop = meta_tag.split(' ')[2]
        first_idx, end_idx = find_index(content_prop)
        url = content_prop[first_idx: end_idx]

        page_dict = dict()
        page_dict['outer_url_list'] = outer_url
        page_dict['url'] = url
        page_dict['keyword_point'] = re.sub('[^a-z]+', ' ', page.lower()).split().count(word.lower())
        page_dict['link_point'] = 0
        page_infos.append(page_dict)

    for page_info in page_infos:
        for outer_url in page_info['outer_url_list']:
            for outer_url_page_candidate in page_infos:
                if outer_url == outer_url_page_candidate['url']:
                    outer_url_page_candidate['link_point'] += page_info['keyword_point'] / len(page_info['outer_url_list'])
                    
    point_lst = [page_info['keyword_point'] + page_info['link_point'] for page_info in page_infos]

    return point_lst.index(max(point_lst))
