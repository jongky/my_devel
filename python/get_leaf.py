json_str = '''{
    "text": "United States",
    "level": "country",
    "children": [
        {
            "text": "Wyoming",
            "level": "region",
            "children": [
                {
                    "text": "Greybull",
                    "level": "city",
                    "children": [
                        {
                            "text": "Greybull-1007",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1007",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "text": "Alaska",
            "level": "region",
            "children": [
                {
                    "text": "Scammon Bay",
                    "level": "city",
                    "children": [
                        {
                            "text": "Scammon Bay-1008",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1008",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "text": "North Carolina",
            "level": "region",
            "children": [
                {
                    "text": "Jacksonville",
                    "level": "city",
                    "children": [
                        {
                            "text": "Jacksonville-1005",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1005",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "text": "Montana",
            "level": "region",
            "children": [
                {
                    "text": "Lame Deer",
                    "level": "city",
                    "children": [
                        {
                            "text": "Lame Deer-1006",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1006",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                },
                {
                    "text": "Homestead",
                    "level": "city",
                    "children": [
                        {
                            "text": "Homestead-1003",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1003",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "text": "Missouri",
            "level": "region",
            "children": [
                {
                    "text": "Long Lane",
                    "level": "city",
                    "children": [
                        {
                            "text": "Long Lane-1001",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1001",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "text": "Illinois",
            "level": "region",
            "children": [
                {
                    "text": "Thayer",
                    "level": "city",
                    "children": [
                        {
                            "text": "Thayer-1002",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1002",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "text": "New Jersey",
            "level": "region",
            "children": [
                {
                    "text": "Bayonne",
                    "level": "city",
                    "children": [
                        {
                            "text": "Bayonne-1009",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1009",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "text": "New Mexico",
            "level": "region",
            "children": [
                {
                    "text": "Los Alamos",
                    "level": "city",
                    "children": [
                        {
                            "text": "Los Alamos-1010",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1010",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "text": "New York",
            "level": "region",
            "children": [
                {
                    "text": "Hoffmeister",
                    "level": "city",
                    "children": [
                        {
                            "text": "Hoffmeister-1004",
                            "level": "campus",
                            "children": [
                                {
                                    "text": "1004",
                                    "level": "rfd",
                                    "leaf": true
                                }
                            ]
                        }
                    ]
                }
            ]
        }
    ]
}'''

import json
import Queue

def get_leaf_nodes(json_str):
    d = json.loads(json_str)
    q = Queue.Queue()
    q.put(d)
    list_of_children = list()
    while not q.empty():
        inner_dict = q.get()
        if isinstance(inner_dict, dict):
            if 'children' in inner_dict.keys():
                try:
                    for child in inner_dict['children']:
                        q.put(child)
                except Exception, e:
                    print e  # or log error or do nothing
            if inner_dict.get('leaf', False) is True:
                list_of_children.append(inner_dict)
        else:
            continue  # or do something else if inner_dict is not a dict object
    return list_of_children

print get_leaf_nodes(json_str)
